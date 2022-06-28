# $NetBSD: Makefile,v 1.3 2022/06/28 11:31:42 wiz Exp $

DISTNAME=	diff-so-fancy-1.4.3
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_GITHUB:=so-fancy/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/so-fancy/diff-so-fancy
COMMENT=	Optimize diffs for human readability
LICENSE=	mit

INSTALLATION_DIRS+=	bin libexec/diff-so-fancy/lib

REPLACE_PERL+=	diff-so-fancy

USE_TOOLS+=	perl:run

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/diff-so-fancy ${DESTDIR}${PREFIX}/libexec/diff-so-fancy
	${INSTALL_DATA} ${WRKSRC}/lib/* ${DESTDIR}${PREFIX}/libexec/diff-so-fancy/lib
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -s ../libexec/diff-so-fancy/diff-so-fancy .

.include "../../mk/bsd.pkg.mk"
