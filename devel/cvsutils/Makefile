# $NetBSD: Makefile,v 1.15 2022/06/28 11:31:42 wiz Exp $

DISTNAME=		cvsutils-0.2.6
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		https://www.red-bean.com/cvsutils/releases/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.red-bean.com/cvsutils/
COMMENT=		CVS utilities to facilitate working

GNU_CONFIGURE=		yes
USE_TOOLS+=		perl:run

REPLACE_PERL=		*.pl
REPLACE_SH=		*.sh

.include "../../mk/bsd.pkg.mk"
