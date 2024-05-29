# $NetBSD: Makefile,v 1.2 2024/05/29 16:33:20 adam Exp $

DISTNAME=	dovecot-fts-flatcurve-1.0.2
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=slusarz/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	dovecot-fts-flatcurve

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/slusarz/dovecot-fts-flatcurve/
COMMENT=	Dovecot FTS Flatcurve plugin (Xapian)
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf autoheader automake m4 pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-hardening
USE_LANGUAGES=		c c++

pre-configure:
	set -e; cd ${WRKSRC}; autoreconf -i

.include "../../mail/dovecot2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
