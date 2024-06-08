# $NetBSD: Makefile,v 1.3 2024/06/08 08:35:53 adam Exp $

DISTNAME=	dovecot-fts-flatcurve-1.0.3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=slusarz/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/slusarz/dovecot-fts-flatcurve/
COMMENT=	Dovecot FTS Flatcurve plugin (Xapian)
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf autoheader automake m4 pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-hardening

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../mail/dovecot2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
