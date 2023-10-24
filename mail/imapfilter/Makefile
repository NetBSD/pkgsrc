# $NetBSD: Makefile,v 1.50 2023/10/24 22:09:44 wiz Exp $

DISTNAME=	imapfilter-2.7.5
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=lefcha/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/lefcha/imapfilter
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
