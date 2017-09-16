# $NetBSD: Makefile,v 1.3 2017/09/16 14:27:48 ryoon Exp $

DISTNAME=	lowdown-VERSION_0_2_4
PKGNAME=	lowdown-0.2.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=kristapsdz/}
GITHUB_TAG=	VERSION_0_2_4

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kristaps.bsd.lv/lowdown/
COMMENT=	Simple Markdown translator
LICENSE=	2-clause-bsd

HAS_CONFIGURE=	yes

SUBST_CLASSES+=		install
SUBST_SED.install+=	-e 's,/usr/local,${PREFIX},' \
			-e 's,^MANDIR=.*,MANDIR=${PREFIX}/${PKGMANDIR},'
SUBST_FILES.install+=	configure
SUBST_STAGE.install=	pre-configure
SUBST_MESSAGE.install=	Fixing installation path.

.include "../../mk/bsd.pkg.mk"
