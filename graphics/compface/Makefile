# $NetBSD: Makefile,v 1.26 2019/08/11 13:21:08 wiz Exp $

DISTNAME=	compface-1.5.2
PKGREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XEMACS:=aux/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freshmeat.net/projects/compface/
COMMENT=	48x48x1 image compression and decompression (X-face utility)

CONFLICTS=	faces-[0-9]*

USE_TOOLS+=		gmake perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		INSTALL_PROGRAM=${BSD_INSTALL_PROGRAM:Q}
CONFIGURE_ENV+=		INSTALL_SCRIPT=${BSD_INSTALL_SCRIPT:Q}
CONFIGURE_ENV+=		INSTALL_DATA=${BSD_INSTALL_DATA:Q}

SUBST_CLASSES+=		perlpath
SUBST_MESSAGE.perlpath=	Configuring Perl path.
SUBST_STAGE.perlpath=	pre-configure
SUBST_FILES.perlpath=	xbm2xface.pl
SUBST_SED.perlpath+=	-e 's|/usr/bin/perl|${PERL5}|g'

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xbm2xface.pl ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
