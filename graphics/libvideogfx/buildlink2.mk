# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/02/13 18:55:41 drochner Exp $
#
# This Makefile fragment is included by packages that use libvideogfx.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(LIBVIDEOGFX_BUILDLINK2_MK)
LIBVIDEOGFX_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libvideogfx
BUILDLINK_DEPENDS.libvideogfx?=		libvideogfx>=1.0.3
BUILDLINK_PKGSRCDIR.libvideogfx?=		../../graphics/libvideogfx

EVAL_PREFIX+=	BUILDLINK_PREFIX.libvideogfx=libvideogfx
BUILDLINK_PREFIX.libvideogfx_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/arch/cpu.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/arch/mmx.h
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/audio/fileio/audiosink.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/audio/fileio/timedsink.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/containers/array.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/containers/array.icc
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/containers/array2.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/containers/array2.icc
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/containers/dynarray.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/containers/heap.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/containers/heap.icc
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/containers/queue.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/containers/queue.icc
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/error.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/color/colorspace.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/color/img2raw.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/datatypes/bitmap.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/datatypes/image.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/datatypes/primitives.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/draw/blit.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/draw/draw.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/draw/format.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/draw/pixelops.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/draw/scale.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/fileio/imagesink.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/fileio/jpeg.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/fileio/mpeg.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/fileio/png.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/fileio/ppm.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/fileio/uyvy.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/fileio/yuv.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/fileio/yuv4mpeg.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/fileio/yuv_vqeg.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/filters/gauss_mmx.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/filters/linear.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/measure/snr.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/graphics/visualize/regions.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/init.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/types.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/utility/bitmanip.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/utility/bitstream/bitbuffer.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/utility/bitstream/bitreader.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/utility/bitstream/bitreader.icc
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/utility/bitstream/bitreader_fast.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/utility/bitstream/bytebuffer.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/utility/fastalloc.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/utility/math.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/utility/refcntr.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/utility/smartpointer.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/x11/dispimg.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/x11/draw_x11.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/x11/imgwin.hh
BUILDLINK_FILES.libvideogfx+=	include/libvideogfx/x11/server.hh
BUILDLINK_FILES.libvideogfx+=	lib/libvideogfx-1.0.*
BUILDLINK_FILES.libvideogfx+=	lib/libvideogfx.*

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

BUILDLINK_TARGETS+=	libvideogfx-buildlink

libvideogfx-buildlink: _BUILDLINK_USE

.endif	# LIBVIDEOGFX_BUILDLINK2_MK
