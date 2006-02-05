# $NetBSD: Makefile,v 1.58 2006/02/05 23:08:12 joerg Exp $

DISTNAME=	nas-1.7b.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://nas.codebrilliance.com/nas/ \
		ftp://ftp.uni-duisburg.de/Sound/NAS/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://radscan.com/nas.html
COMMENT=	Network Audio System

DEPENDS+=	p5-perl-headers-${OS_VERSION}{,nb*}:../../devel/p5-perl-headers

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		gmake
USE_IMAKE=		yes

PKG_SYSCONFSUBDIR=	nas

REPLACE_PERL=		clients/audio/auscope/auscope

pre-configure:
	@cd ${WRKSRC}; for file in					\
		config/NetAudio.def;					\
	do								\
		${SED}	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"	\
			$${file} >> $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done
	@cd ${WRKSRC}; for file in					\
		server/nasd.conf.eg					\
		server/dda/voxware/auvoxware.c;				\
	do								\
		${SED}	-e "s|@DEVOSSAUDIO@|${DEVOSSAUDIO}|g"		\
			$${file} >> $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done
	@cd ${WRKSRC}; for file in					\
		config/mungeman;					\
	do								\
		${SED} -e "s|^[ 	]*#|#|g"			\
			$${file} >> $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
post-install:
	${LN} -s ${PREFIX}/lib/libaudio.so.2.3 ${PREFIX}/lib/libaudio.so.2
.endif

PLIST_SRC=	${PKGDIR}/PLIST.clients

.if ${OPSYS} != "Interix"
.  if (${MACHINE_ARCH} == "i386") || \
      (${MACHINE_ARCH} == "sparc")
.    include "../../mk/ossaudio.buildlink3.mk"
EGDIR=		${PREFIX}/share/examples/nas
CONF_FILES=	${EGDIR}/nasd.conf.eg ${PKG_SYSCONFDIR}/nasd.conf
.    if ${OPSYS} != "SunOS"
PLIST_SRC+=	${PKGDIR}/PLIST.voxware
.    endif
PLIST_SRC+=	${PKGDIR}/PLIST.server
.  endif
.endif

.include "../../mk/bsd.pkg.mk"
