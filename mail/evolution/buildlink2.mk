# $NetBSD: buildlink2.mk,v 1.7 2004/01/14 07:27:51 xtraeme Exp $
#
# This Makefile fragment is included by packages that use evolution.
#
# This file was created automatically using createbuildlink 2.9.
#

.if !defined(EVOLUTION_BUILDLINK2_MK)
EVOLUTION_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			evolution
BUILDLINK_DEPENDS.evolution?=		evolution>=1.4.5nb1
BUILDLINK_PKGSRCDIR.evolution?=		../../mail/evolution

EVAL_PREFIX+=	BUILDLINK_PREFIX.evolution=evolution
BUILDLINK_PREFIX.evolution_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.evolution+=	include/evolution-1.4/cal-client/*.h
BUILDLINK_FILES.evolution+=	include/evolution-1.4/cal-util/*.h
BUILDLINK_FILES.evolution+=	include/evolution-1.4/camel/*.h
BUILDLINK_FILES.evolution+=	include/evolution-1.4/e-conduit/*.h
BUILDLINK_FILES.evolution+=	include/evolution-1.4/e-db3util/*.h
BUILDLINK_FILES.evolution+=	include/evolution-1.4/e-util/*.h
BUILDLINK_FILES.evolution+=	include/evolution-1.4/ebook/*.h
BUILDLINK_FILES.evolution+=	include/evolution-1.4/ename/*.h
BUILDLINK_FILES.evolution+=	include/evolution-1.4/*.h
BUILDLINK_FILES.evolution+=	include/evolution-1.4/importer/*.h
BUILDLINK_FILES.evolution+=	include/evolution-1.4/pas/*.h
BUILDLINK_FILES.evolution+=	include/evolution-1.4/pcs/*.h
BUILDLINK_FILES.evolution+=	include/evolution-1.4/shell/*.h
BUILDLINK_FILES.evolution+=	include/evolution-1.4/widgets/*.h
BUILDLINK_FILES.evolution+=	lib/bonobo/servers/GNOME_Evolution_Addressbook.server
BUILDLINK_FILES.evolution+=	lib/bonobo/servers/GNOME_Evolution_Addressbook_LDIF_Importer.server
BUILDLINK_FILES.evolution+=	lib/bonobo/servers/GNOME_Evolution_Addressbook_SelectNames.server
BUILDLINK_FILES.evolution+=	lib/bonobo/servers/GNOME_Evolution_Addressbook_VCard_Importer.server
BUILDLINK_FILES.evolution+=	lib/bonobo/servers/GNOME_Evolution_Calendar.server
BUILDLINK_FILES.evolution+=	lib/bonobo/servers/GNOME_Evolution_Calendar_AlarmNotify.server
BUILDLINK_FILES.evolution+=	lib/bonobo/servers/GNOME_Evolution_Calendar_Importer.server
BUILDLINK_FILES.evolution+=	lib/bonobo/servers/GNOME_Evolution_Mail.server
BUILDLINK_FILES.evolution+=	lib/bonobo/servers/GNOME_Evolution_Mail_Elm_Intelligent_Importer.server
BUILDLINK_FILES.evolution+=	lib/bonobo/servers/GNOME_Evolution_Mail_Mbox_Importer.server
BUILDLINK_FILES.evolution+=	lib/bonobo/servers/GNOME_Evolution_Mail_Netscape_Intelligent_Importer.server
BUILDLINK_FILES.evolution+=	lib/bonobo/servers/GNOME_Evolution_Mail_Outlook_Importer.server
BUILDLINK_FILES.evolution+=	lib/bonobo/servers/GNOME_Evolution_Mail_Pine_Intelligent_Importer.server
BUILDLINK_FILES.evolution+=	lib/bonobo/servers/GNOME_Evolution_Shell.server
BUILDLINK_FILES.evolution+=	lib/bonobo/servers/GNOME_Evolution_Summary.server
BUILDLINK_FILES.evolution+=	lib/bonobo/servers/GNOME_Evolution_Wombat.server
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/camel-providers/libcamelimap.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/camel-providers/libcamelimap.urls
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/camel-providers/libcamellocal.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/camel-providers/libcamellocal.urls
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/camel-providers/libcamelpop3.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/camel-providers/libcamelpop3.urls
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/camel-providers/libcamelsendmail.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/camel-providers/libcamelsendmail.urls
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/camel-providers/libcamelsmtp.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/camel-providers/libcamelsmtp.urls
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/components/libevolution-addressbook.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/components/libevolution-calendar.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/components/libevolution-executive-summary.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/components/libevolution-mail.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/evolution-calendar-importers/libevolution-calendar-importers.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/evolution-mail-importers/libevolution-elm-importer.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/evolution-mail-importers/libevolution-netscape-importer.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/evolution-mail-importers/libevolution-pine-importer.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/evolution-mail-importers/libmbox.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/evolution-mail-importers/liboutlook.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libcal-client.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libcal-util-static.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libcal-util.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libcamel.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libebook-static.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libebook.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libeconduit.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libedb3util.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libemiscwidgets.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libename.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libeshell.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libetimezonedialog.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libeutil.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libevolution-importer.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libical-evolution.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libicalvcal-evolution.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libmenus.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libpas.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libpcs.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libversit.*
BUILDLINK_FILES.evolution+=	lib/evolution/1.4/libwombat.*

.include "../../databases/db3/buildlink2.mk"
.include "../../databases/openldap/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/gal2/buildlink2.mk"
.include "../../devel/libbonoboui/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../print/libgnomeprint/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../textproc/libunicode/buildlink2.mk"
.include "../../www/gtkhtml3/buildlink2.mk"

BUILDLINK_TARGETS+=	evolution-buildlink

evolution-buildlink: _BUILDLINK_USE

.endif	# EVOLUTION_BUILDLINK2_MK
