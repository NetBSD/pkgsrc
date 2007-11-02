# $NetBSD: Makefile,v 1.19 2007/11/02 09:17:33 rillig Exp $
#

DISTNAME=		fort77-1.18
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SUNSITE:=devel/lang/fortran/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		The driver for f2c, a fortran to C translator

BUILD_TARGET=		test
USE_TOOLS+=		perl:run

REPLACE_PERL=		fort77 tests/test.pl

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	pre-configure
SUBST_FILES.perl=	fort77 tests/test.pl
SUBST_SED.perl=		-e 's,/usr/bin/perl,${PERL5},'

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
INSTALLATION_DIRS_FROM_PLIST=	yes

.include "../../lang/f2c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
