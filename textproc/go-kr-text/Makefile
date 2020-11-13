# $NetBSD: Makefile,v 1.7 2020/11/13 19:26:22 bsiegert Exp $

DISTNAME=		go-kr-text-0.2.0
PKGREVISION=		6
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=kr/}
GITHUB_PROJECT=		text
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/kr/text
COMMENT=		Go package for manipulating paragraphs of text
LICENSE=		mit

GO_SRCPATH=		github.com/kr/text
GO_DIST_BASE=		${DISTNAME:S/go-kr-//}

# upstream should at least pick better names for the binaries,
# avoid PLIST conflicts with well-known binaries. Since in the
# dependency chain I package this for only the library parts are used,
# this is okay.
post-build:
	${MV} ${WRKDIR}/bin/agg ${WRKDIR}/bin/go-agg
	${MV} ${WRKDIR}/bin/mc ${WRKDIR}/bin/go-mc

.include "../../devel/go-pty/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
