# $NetBSD: Makefile,v 1.21 2002/12/03 09:13:39 jlam Exp $
# FreeBSD ID: Makefile,v 1.8 1997/01/06 12:04:12 jkh Exp
#

DISTNAME=	nas-1.6.src
PKGNAME=	${DISTNAME:S/.src//}
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	audio
MASTER_SITES=	http://radscan.com/nas/ \
		ftp://ftp.uni-duisburg.de/Sound/NAS/ \

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://radscan.com/nas.html
COMMENT=	Network Audio System

USE_BUILDLINK2=		# defined
USE_IMAKE=		# defined
USE_X11BASE=		# defined

PKG_SYSCONFSUBDIR=	nas

pre-configure:
	cd ${WRKSRC}; for file in					\
		config/NetAudio.def;					\
	do								\
		${SED}	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"	\
			$${file} >> $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done
	cd ${WRKSRC}; for file in					\
		server/nasd.conf.eg					\
		server/dda/voxware/auvoxware.c;				\
	do								\
		${SED}	-e "s|@DEVOSSAUDIO@|${DEVOSSAUDIO}|g"		\
			$${file} >> $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

PLIST_SRC=	${PKGDIR}/PLIST.clients
.if (${MACHINE_ARCH} == "i386") || \
    (${MACHINE_ARCH} == "sparc")
.  include "../../mk/ossaudio.buildlink2.mk"
EGDIR=		${PREFIX}/share/examples/nas
PLIST_SRC+=	${PKGDIR}/PLIST.voxware
CONF_FILES=	${EGDIR}/nasd.conf.eg ${PKG_SYSCONFDIR}/nasd.conf
.endif

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
