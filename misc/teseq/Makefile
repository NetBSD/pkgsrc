# $NetBSD: Makefile,v 1.13 2019/08/11 13:22:00 wiz Exp $

DISTNAME=	teseq-1.1.1
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	http://ftp.gnu.org/gnu/teseq/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ftp.gnu.org/gnu/teseq/
COMMENT=	Terminal control sequence analyzer
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c99
USE_TOOLS+=	perl:run

CONFIGURE_ENV+=	AUTOCONF=true # files pre-built, not needed
CONFIGURE_ENV+= MAKEINFO=true
CONFIGURE_ENV+=	HELP2MAN=true

INFO_FILES=	yes

REPLACE_PERL=	reseq.in
REPLACE_SH=	tests/run.in

SUBST_CLASSES+=	infodir
SUBST_FILES.infodir=	Makefile.in
SUBST_MESSAGE.infodir=	Fixing info directory pathname
SUBST_SED.infodir=	-e 's,@infodir@,${PREFIX}/${PKGINFODIR},g'
SUBST_STAGE.infodir=	pre-configure

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
