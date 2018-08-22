# $NetBSD: Makefile,v 1.32 2018/08/22 09:45:19 wiz Exp $
#

DISTNAME=		fort77-1.18
PKGREVISION=		8
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SUNSITE:=devel/lang/fortran/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		The driver for f2c, a fortran to C translator

DEPENDS+=		f2c-[0-9]*:../../lang/f2c

USE_TOOLS+=		perl:run
NO_BUILD=		yes
TEST_TARGET=		test
AUTO_MKDIRS=		yes

REPLACE_PERL=		fort77 tests/test.pl

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	pre-configure
SUBST_FILES.perl=	fort77 tests/test.pl
SUBST_SED.perl=		-e 's,/usr/bin/perl,${PERL5},'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fort77 ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/fort77.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/libf2c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
