# $NetBSD: buildlink2.mk,v 1.1 2004/03/29 09:34:26 kei Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.Gauche?=	build

.if !defined(GAUCHE_BUILDLINK2_MK)
GAUCHE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		Gauche
BUILDLINK_DEPENDS.Gauche?=	Gauche>=0.7.4.2
BUILDLINK_PKGSRCDIR.Gauche?=	../../lang/gauche

EVAL_PREFIX+=	BUILDLINK_PREFIX.Gauche=Gauche
BUILDLINK_PREFIX.Gauche_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/${MACHINE_GNU_PLATFORM}/auxsys.*
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/${MACHINE_GNU_PLATFORM}/binary.*
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/${MACHINE_GNU_PLATFORM}/fcntl.*
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/${MACHINE_GNU_PLATFORM}/gauche-config
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/${MACHINE_GNU_PLATFORM}/gosh
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/${MACHINE_GNU_PLATFORM}/libcharconv.*
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/${MACHINE_GNU_PLATFORM}/libgauche-uvector.*
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/${MACHINE_GNU_PLATFORM}/libgauche.*
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/${MACHINE_GNU_PLATFORM}/libnet.*
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/${MACHINE_GNU_PLATFORM}/md5.*
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/${MACHINE_GNU_PLATFORM}/mt-random.*
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/${MACHINE_GNU_PLATFORM}/ndbm.*
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/${MACHINE_GNU_PLATFORM}/sha1.*
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/${MACHINE_GNU_PLATFORM}/syslog.*
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/${MACHINE_GNU_PLATFORM}/termios.*
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/${MACHINE_GNU_PLATFORM}/threads.*
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/include/gauche.h
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/include/gauche/arch.h
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/include/gauche/char_euc_jp.h
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/include/gauche/char_none.h
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/include/gauche/char_sjis.h
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/include/gauche/char_utf_8.h
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/include/gauche/class.h
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/include/gauche/config.h
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/include/gauche/exception.h
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/include/gauche/extend.h
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/include/gauche/int64.h
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/include/gauche/net.h
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/include/gauche/pthread.h
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/include/gauche/scmconst.h
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/include/gauche/uthread.h
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/include/gauche/uvector.h
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/include/gauche/vm.h
BUILDLINK_FILES.Gauche+=	lib/gauche/${PKGVERSION}/include/gauche/vminsn.h
BUILDLINK_FILES.Gauche+=	lib/libgauche.*

.include "../../devel/boehm-gc/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"

BUILDLINK_TARGETS+=	Gauche-buildlink

Gauche-buildlink: _BUILDLINK_USE

.endif	# GAUCHE_BUILDLINK2_MK
