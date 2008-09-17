# $NetBSD: Makefile,v 1.2 2008/09/17 00:14:23 bjs Exp $
#

DISTNAME=		cvsutils-0.2.5
CATEGORIES=		devel
MASTER_SITES=		http://www.red-bean.com/cvsutils/releases/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.red-bean.com/cvsutils/
COMMENT=		CVS utilities to facilitate working

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		perl:run

REPLACE_PERL=		*.pl
REPLACE_SH=		*.sh

.include "../../mk/bsd.pkg.mk"
