# $NetBSD: Makefile,v 1.17 2009/06/11 10:04:27 tnn Exp $

DISTNAME=	compface-1.5.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://ftp.xemacs.org/pub/xemacs/aux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freshmeat.net/projects/compface/
COMMENT=	48x48x1 image compression and decompression (X-face utility)

CONFLICTS=	faces-[0-9]*
PKG_DESTDIR_SUPPORT=	user-destdir

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
