# $NetBSD: Makefile,v 1.50 2005/01/21 21:40:43 tv Exp $

DISTNAME=	nas-1.7.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	audio
MASTER_SITES=	http://nas.codebrilliance.com/nas/ \
		ftp://ftp.uni-duisburg.de/Sound/NAS/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://radscan.com/nas.html
COMMENT=	Network Audio System

DEPENDS+=	p5-perl-headers-${OS_VERSION}{,nb*}:../../devel/p5-perl-headers

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGINSTALL=		yes
USE_IMAKE=		yes

PKG_SYSCONFSUBDIR=	nas

REPLACE_PERL=		clients/audio/auscope/auscope

post-patch:
	@for f in `${FIND} ${WRKSRC} -name '*.[ch]' -print`; do		\
		${SED} -e "s|<malloc.h>|<stdlib.h>|g" $$f > $$f.patch	\
		&& ${MV} $$f.patch $$f;					\
	done

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

PLIST_SRC=	${PKGDIR}/PLIST.clients

.if ${OPSYS} != "Interix"
.  if (${MACHINE_ARCH} == "i386") || \
      (${MACHINE_ARCH} == "sparc")
.    include "../../mk/ossaudio.buildlink3.mk"
EGDIR=		${PREFIX}/share/examples/nas
PLIST_SRC+=	${PKGDIR}/PLIST.voxware
CONF_FILES=	${EGDIR}/nasd.conf.eg ${PKG_SYSCONFDIR}/nasd.conf
.  endif
.endif

.include "../../mk/bsd.pkg.mk"
