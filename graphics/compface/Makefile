# $NetBSD: Makefile,v 1.14 2007/03/08 19:23:04 wiz Exp $

DISTNAME=	compface-1.5.2
CATEGORIES=	graphics
MASTER_SITES=	http://ftp.xemacs.org/pub/xemacs/aux/

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://freshmeat.net/projects/compface/
COMMENT=	48x48x1 image compression and decompression (X-face utility)

CONFLICTS=	faces-[0-9]*

USE_TOOLS+=		gmake
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
	${INSTALL_SCRIPT} ${WRKSRC}/xbm2xface.pl ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
