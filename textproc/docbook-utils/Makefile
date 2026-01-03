# $NetBSD: Makefile,v 1.2 2026/01/03 23:58:47 wiz Exp $

DISTNAME=	docbook-utils-0.6.15
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=devexp-db/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/devexp-db/docbook-utils/
COMMENT=	Shell scripts for managing DocBook documents
LICENSE=	gnu-gpl-v2

DEPENDS+=	html-[0-9]*:../../textproc/html
DEPENDS+=	dsssl-docbook-modular-[0-9]*:../../textproc/dsssl-docbook-modular
DEPENDS+=	openjade-[0-9]*:../../textproc/openjade
DEPENDS+=	p5-SGMLS-[0-9]*:../../textproc/p5-SGMLS

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS=	autoreconf autoconf automake gmake

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Substituting /etc with PKG_SYSCONFDIR
SUBST_SED.paths=	-e 's|/etc|${PKG_SYSCONFDIR}|g'
SUBST_FILES.paths=	bin/jw.in
SUBST_FILES.paths+=	doc/refentry/frontend-spec.sgml doc/refentry/jw.sgml

REPLACE_PERL+=	bin/sgmldiff.in

#CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc

MAKE_ENV=	SYSCONFDIR=${PKG_SYSCONFDIR:Q}

pre-configure:
	cd ${WRKSRC} && autoreconf -vi

.include "../../lang/perl5/buildlink3.mk"
.include "../../textproc/opensp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
