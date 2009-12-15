# $NetBSD: Makefile,v 1.23 2009/12/15 17:27:13 asau Exp $
#

DISTNAME=		fort77-1.18
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SUNSITE:=devel/lang/fortran/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		The driver for f2c, a fortran to C translator

DEPENDS+=		f2c-[0-9]*:../../lang/f2c

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		test
USE_TOOLS+=		perl:run

REPLACE_PERL=		fort77 tests/test.pl

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	pre-configure
SUBST_FILES.perl=	fort77 tests/test.pl
SUBST_SED.perl=		-e 's,/usr/bin/perl,${PERL5},'

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
AUTO_MKDIRS=			yes

.include "../../devel/libf2c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
