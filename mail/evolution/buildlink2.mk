# $NetBSD: buildlink2.mk,v 1.5 2003/11/12 01:31:50 salo Exp $
#

.if !defined(EVOLUTION_BUILDLINK2_MK)
EVOLUTION_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			evolution
BUILDLINK_DEPENDS.evolution?=		evolution>=1.2.4nb4
BUILDLINK_PKGSRCDIR.evolution?=		../../mail/evolution

EVAL_PREFIX+=	BUILDLINK_PREFIX.evolution=evolution
BUILDLINK_PREFIX.evolution_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.evolution+=	include/camel/*.h
BUILDLINK_FILES.evolution+=	include/camel/camel-exception-list.def
BUILDLINK_FILES.evolution+=	include/ename/e-address-western.h
BUILDLINK_FILES.evolution+=	include/ename/e-name-western-tables.h
BUILDLINK_FILES.evolution+=	include/ename/e-name-western.h
BUILDLINK_FILES.evolution+=	include/evolution/cal-client/*.h
BUILDLINK_FILES.evolution+=	include/evolution/cal-util/*.h
BUILDLINK_FILES.evolution+=	include/evolution/ebook/*.h
BUILDLINK_FILES.evolution+=	include/evolution/ical.h
BUILDLINK_FILES.evolution+=	include/evolution/importer/*.h
BUILDLINK_FILES.evolution+=	include/evolution/shell/*.h
BUILDLINK_FILES.evolution+=	include/evolution/wombat/wombat-client.h
BUILDLINK_FILES.evolution+=	lib/evolution/camel-providers/1.0/libcamelimap.*
BUILDLINK_FILES.evolution+=	lib/evolution/camel-providers/1.0/libcamelimap.urls
BUILDLINK_FILES.evolution+=	lib/evolution/camel-providers/1.0/libcamellocal.*
BUILDLINK_FILES.evolution+=	lib/evolution/camel-providers/1.0/libcamellocal.urls
BUILDLINK_FILES.evolution+=	lib/evolution/camel-providers/1.0/libcamelnntp.*
BUILDLINK_FILES.evolution+=	lib/evolution/camel-providers/1.0/libcamelnntp.urls
BUILDLINK_FILES.evolution+=	lib/evolution/camel-providers/1.0/libcamelpop3.*
BUILDLINK_FILES.evolution+=	lib/evolution/camel-providers/1.0/libcamelpop3.urls
BUILDLINK_FILES.evolution+=	lib/evolution/camel-providers/1.0/libcamelsendmail.*
BUILDLINK_FILES.evolution+=	lib/evolution/camel-providers/1.0/libcamelsendmail.urls
BUILDLINK_FILES.evolution+=	lib/evolution/camel-providers/1.0/libcamelsmtp.*
BUILDLINK_FILES.evolution+=	lib/evolution/camel-providers/1.0/libcamelsmtp.urls
BUILDLINK_FILES.evolution+=	lib/evolution/evolution-mail-importers/${PKGVERSION}/libmbox.*
BUILDLINK_FILES.evolution+=	lib/evolution/evolution-mail-importers/${PKGVERSION}/liboutlook.*
BUILDLINK_FILES.evolution+=	lib/libcal-client.*
BUILDLINK_FILES.evolution+=	lib/libcal-util.*
BUILDLINK_FILES.evolution+=	lib/libcamel.*
BUILDLINK_FILES.evolution+=	lib/libebook.*
BUILDLINK_FILES.evolution+=	lib/libename.*
BUILDLINK_FILES.evolution+=	lib/libeselectnames.*
BUILDLINK_FILES.evolution+=	lib/libeshell.*
BUILDLINK_FILES.evolution+=	lib/libevolution-importer.*
BUILDLINK_FILES.evolution+=	lib/libical-evolution.*
BUILDLINK_FILES.evolution+=	lib/libwombat.*
BUILDLINK_FILES.evolution+=	share/idl/Composer.idl
BUILDLINK_FILES.evolution+=	share/idl/Evolution-Activity.idl
BUILDLINK_FILES.evolution+=	share/idl/Evolution-Composer.idl
BUILDLINK_FILES.evolution+=	share/idl/Evolution-Offline.idl
BUILDLINK_FILES.evolution+=	share/idl/Evolution-Session.idl
BUILDLINK_FILES.evolution+=	share/idl/Evolution-Shell.idl
BUILDLINK_FILES.evolution+=	share/idl/Evolution-ShellComponent.idl
BUILDLINK_FILES.evolution+=	share/idl/Evolution-ShellComponentDnd.idl
BUILDLINK_FILES.evolution+=	share/idl/Evolution-ShellView.idl
BUILDLINK_FILES.evolution+=	share/idl/Evolution-Shortcuts.idl
BUILDLINK_FILES.evolution+=	share/idl/Evolution-Storage.idl
BUILDLINK_FILES.evolution+=	share/idl/Evolution-StorageSetView.idl
BUILDLINK_FILES.evolution+=	share/idl/Evolution-Wizard.idl
BUILDLINK_FILES.evolution+=	share/idl/Evolution-common.idl
BUILDLINK_FILES.evolution+=	share/idl/Evolution.idl
BUILDLINK_FILES.evolution+=	share/idl/GNOME_Evolution_Importer.idl
BUILDLINK_FILES.evolution+=	share/idl/addressbook.idl
BUILDLINK_FILES.evolution+=	share/idl/evolution-calendar.idl

.include "../../textproc/libunicode/buildlink2.mk"
.include "../../sysutils/gnome-vfs/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../databases/db3/buildlink2.mk"
.include "../../databases/openldap/buildlink2.mk"
.include "../../www/gtkhtml/buildlink2.mk"
.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/bonobo-conf/buildlink2.mk"
.include "../../devel/oaf/buildlink2.mk"
.include "../../devel/gal/buildlink2.mk"
.include "../../net/ORBit/buildlink2.mk"

BUILDLINK_TARGETS+=	evolution-buildlink

evolution-buildlink: _BUILDLINK_USE

.endif	# EVOLUTION_BUILDLINK2_MK
