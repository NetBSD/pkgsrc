# $NetBSD: Makefile,v 1.39 2022/06/28 11:35:29 wiz Exp $

DISTNAME=	if-psprint-1.10
PKGREVISION=	11
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=abs0/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	https://github.com/abs0/if-psprint
COMMENT=	Print text or postscript to arbitrary printer, can use smb
LICENSE=	public-domain

DEPENDS+=	enscript>=1.6.3nb1:../../print/enscript

REPLACE_PERL=	if-psprint.pl
USE_TOOLS+=	gs:run perl:run pod2man

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_FILES.manpath=	Makefile
SUBST_SED.manpath=	-e 's,man/,${PKGMANDIR}/,g'

.include "../../mk/bsd.pkg.mk"
