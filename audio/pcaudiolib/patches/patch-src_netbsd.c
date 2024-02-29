$NetBSD: patch-src_netbsd.c,v 1.1 2024/02/29 14:15:41 bsiegert Exp $

Add NetBSD native audio support

--- src/netbsd.c.orig	2024-01-30 02:16:50.046541412 +0000
+++ src/netbsd.c
@@ -0,0 +1,193 @@
+/* Netbsd Output.
+ *
+ * Based on Oss Output by Reece H. Dunn
+ *
+ * This file is part of pcaudiolib.
+ *
+ * pcaudiolib is free software: you can redistribute it and/or modify
+ * it under the terms of the GNU General Public License as published by
+ * the Free Software Foundation, either version 3 of the License, or
+ * (at your option) any later version.
+ *
+ * pcaudiolib is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ * GNU General Public License for more details.
+ *
+ * You should have received a copy of the GNU General Public License
+ * along with pcaudiolib.  If not, see <http://www.gnu.org/licenses/>.
+ */
+
+#include "config.h"
+#include "audio_priv.h"
+
+#include <sys/audioio.h>
+
+#include <errno.h>
+#include <fcntl.h>
+#include <string.h>
+#include <stdio.h>
+#include <sys/ioctl.h>
+#include <unistd.h>
+
+struct netbsd_object
+{
+	struct audio_object vtable;
+	int fd;
+	int ctlfd;
+	char *device;
+
+};
+
+#define to_netbsd_object(object) container_of(object, struct netbsd_object, vtable)
+
+int
+netbsd_object_open(struct audio_object *object,
+                enum audio_object_format format,
+                uint32_t rate,
+                uint8_t channels)
+{
+	struct netbsd_object *self = to_netbsd_object(object);
+		
+	if (self->fd != -1)
+		return EEXIST;
+
+	struct aformat_sun
+	{
+		int audio_object_format;
+		int netbsd_format;
+		int netbsd_precision;
+	};
+	struct aformat_sun aformat_netbsd_tbl[] = {
+		{AUDIO_OBJECT_FORMAT_ALAW, AUDIO_ENCODING_ALAW, 8},
+		{AUDIO_OBJECT_FORMAT_ULAW, AUDIO_ENCODING_ULAW, 8},
+		{AUDIO_OBJECT_FORMAT_S8, AUDIO_ENCODING_SLINEAR, 8},
+		{AUDIO_OBJECT_FORMAT_U8, AUDIO_ENCODING_ULINEAR, 8},
+		{AUDIO_OBJECT_FORMAT_S16LE, AUDIO_ENCODING_SLINEAR_LE, 16},
+		{AUDIO_OBJECT_FORMAT_S16BE, AUDIO_ENCODING_SLINEAR_BE, 16},
+		{AUDIO_OBJECT_FORMAT_U16LE, AUDIO_ENCODING_ULINEAR_LE, 16},
+		{AUDIO_OBJECT_FORMAT_U16BE, AUDIO_ENCODING_ULINEAR_BE, 16},
+		{AUDIO_OBJECT_FORMAT_S18LE, AUDIO_ENCODING_SLINEAR_LE, 18},
+		{AUDIO_OBJECT_FORMAT_S18BE, AUDIO_ENCODING_SLINEAR_BE, 18},
+		{AUDIO_OBJECT_FORMAT_U18LE, AUDIO_ENCODING_ULINEAR_LE, 18},
+		{AUDIO_OBJECT_FORMAT_U18BE, AUDIO_ENCODING_ULINEAR_BE, 18},
+		{AUDIO_OBJECT_FORMAT_S20LE, AUDIO_ENCODING_SLINEAR_LE, 20},
+		{AUDIO_OBJECT_FORMAT_S20BE, AUDIO_ENCODING_SLINEAR_BE, 20},
+		{AUDIO_OBJECT_FORMAT_U20LE, AUDIO_ENCODING_ULINEAR_LE, 20},
+		{AUDIO_OBJECT_FORMAT_U20BE, AUDIO_ENCODING_ULINEAR_BE, 20},
+		{AUDIO_OBJECT_FORMAT_S24LE, AUDIO_ENCODING_SLINEAR_LE, 24},
+		{AUDIO_OBJECT_FORMAT_S24BE, AUDIO_ENCODING_SLINEAR_BE, 24},
+		{AUDIO_OBJECT_FORMAT_U24LE, AUDIO_ENCODING_ULINEAR_LE, 24},
+		{AUDIO_OBJECT_FORMAT_U24BE, AUDIO_ENCODING_ULINEAR_BE, 24},
+		{AUDIO_OBJECT_FORMAT_S32LE, AUDIO_ENCODING_SLINEAR_LE, 32},
+		{AUDIO_OBJECT_FORMAT_S32BE, AUDIO_ENCODING_SLINEAR_BE, 32},
+		{AUDIO_OBJECT_FORMAT_U32LE, AUDIO_ENCODING_ULINEAR_LE, 32},
+		{AUDIO_OBJECT_FORMAT_U32BE, AUDIO_ENCODING_ULINEAR_BE, 32},
+		{AUDIO_OBJECT_FORMAT_ADPCM, AUDIO_ENCODING_ADPCM, 8},
+	};
+#define NETBSDFORMATS (sizeof(aformat_netbsd_tbl)/sizeof(aformat_netbsd_tbl[0]))
+	int i;
+	for(i=0; i < NETBSDFORMATS; i++)
+		if(aformat_netbsd_tbl[i].audio_object_format == format)
+			break;
+	if(i >= NETBSDFORMATS)
+		return EINVAL;
+
+	audio_info_t audioinfo;
+	if ((self->fd = open(self->device ? self->device : "/dev/audio", O_WRONLY, 0)) == -1)
+		return errno;
+	AUDIO_INITINFO(&audioinfo);
+	audioinfo.play.sample_rate = rate;
+	audioinfo.play.channels = channels;
+	audioinfo.play.precision = aformat_netbsd_tbl[i].netbsd_precision;
+	audioinfo.play.encoding = aformat_netbsd_tbl[i].netbsd_format;
+	if (ioctl(self->fd, AUDIO_SETINFO, &audioinfo) == -1)
+		goto error;
+	return 0;
+error:
+	close(self->fd);
+	self->fd = -1;
+	return errno;
+}
+
+void
+netbsd_object_close(struct audio_object *object)
+{
+	struct netbsd_object *self = to_netbsd_object(object);
+
+	if (self->fd != -1) {
+		close(self->fd);
+		self->fd = -1;
+	}
+}
+
+void
+netbsd_object_destroy(struct audio_object *object)
+{
+	struct netbsd_object *self = to_netbsd_object(object);
+
+	free(self->device);
+	free(self);
+}
+
+int
+netbsd_object_drain(struct audio_object *object)
+{
+	struct netbsd_object *self = to_netbsd_object(object);
+
+	if (ioctl(self->fd, AUDIO_DRAIN, NULL) == -1)
+		return errno;
+	return 0;
+}
+
+int
+netbsd_object_flush(struct audio_object *object)
+{
+	struct netbsd_object *self = to_netbsd_object(object);
+
+       	if (ioctl(self->fd, AUDIO_FLUSH, NULL) == -1)
+		return errno;
+	return 0;
+}
+
+int
+netbsd_object_write(struct audio_object *object,
+                 const void *data,
+                 size_t bytes)
+{
+	struct netbsd_object *self = to_netbsd_object(object);
+
+	if (write(self->fd, data, bytes) == -1)
+		return errno;
+	return 0;
+}
+
+const char *
+netbsd_object_strerror(struct audio_object *object,
+                    int error)
+{
+	return strerror(error);
+}
+
+struct audio_object *
+create_netbsd_object(const char *device,
+                  const char *application_name,
+                  const char *description)
+{
+	struct netbsd_object *self = malloc(sizeof(struct netbsd_object));
+	if (!self)
+		return NULL;
+
+	self->fd = -1;
+	self->device = device ? strdup(device) : NULL;
+
+	self->vtable.open = netbsd_object_open;
+	self->vtable.close = netbsd_object_close;
+	self->vtable.destroy = netbsd_object_destroy;
+	self->vtable.write = netbsd_object_write;
+	self->vtable.drain = netbsd_object_drain;
+	self->vtable.flush = netbsd_object_flush;
+	self->vtable.strerror = netbsd_object_strerror;
+
+	return &self->vtable;
+}
