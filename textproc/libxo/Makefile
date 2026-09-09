# $NetBSD: Makefile,v 1.1 2026/09/09 02:26:33 charlotte Exp $

DISTNAME=	libxo-2.0.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Juniper/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
GITHUB_TYPE=	release

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://github.com/Juniper/libxo
COMMENT=	Library for generating text, XML, JSON, and HTML output
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	autoconf automake gmake msgfmt perl:run

REPLACE_PERL+=	xolint/xolint.pl

CONFIGURE_ARGS+=	MAKE=gmake

pre-configure:
	cd ${WRKSRC} && autoreconf -fi && automake

post-install:
	find ${DESTDIR} -type f -name \*.la -delete

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
