# $NetBSD: Makefile,v 1.52 2025/12/31 08:55:22 wiz Exp $

DISTNAME=	imapfilter-2.7.5
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=lefcha/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lefcha/imapfilter
COMMENT=	Mail filtering utility for the IMAP
LICENSE=	mit

LDFLAGS.SunOS+=		-lsocket -lnsl
LIBS.Linux+=		-ldl
INSTALLATION_DIRS=	share/examples/imapfilter

post-install:
.for f in config.lua extend.lua
	${INSTALL_DATA} ${WRKSRC}/samples/${f} \
		${DESTDIR}${PREFIX}/share/examples/imapfilter
.endfor

.include "../../devel/pcre2/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
