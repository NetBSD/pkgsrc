# $NetBSD: Makefile,v 1.2 2013/09/16 04:47:42 ryoon Exp $

DISTNAME=	mintbin-CVS-20110527
PKGNAME=	cross-freemint-${DISTNAME:S/CVS-//}
PKGREVISION=	1
CATEGORIES=	cross
MASTER_SITES=	http://vincent.riviere.free.fr/soft/m68k-atari-mint/archives/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://vincent.riviere.free.fr/soft/m68k-atari-mint/
COMMENT=	Cross FreeMiNT utility for FreeMiNT
LICENSE=	gnu-gpl-v2

FREEMINT_PREFIX=	${PREFIX}/cross-freemint

USE_TOOLS+=	makeinfo
GNU_CONFIGURE=	yes

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${FREEMINT_PREFIX}

CONFIGURE_ARGS+=	--target=m68k-atari-mint
INFO_FILES=		yes

INSTALLATION_DIRS+=	bin ${FREEMINT_PREFIX}

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}
	${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}


post-install:
	for f in m68k-atari-mint-arconv		m68k-atari-mint-cnm \
		 m68k-atari-mint-csize		m68k-atari-mint-flags \
		 m68k-atari-mint-mintbin	m68k-atari-mint-stack \
		 m68k-atari-mint-cstrip		m68k-atari-mint-symex ; do \
		${LN} -s ${FREEMINT_PREFIX}/m68k-atari-mint/bin/"$$f" \
		  ${DESTDIR}${PREFIX}/bin/"$$f" || exit 1; \
	done

.include "../../mk/bsd.pkg.mk"
