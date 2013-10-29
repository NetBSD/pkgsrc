# $NetBSD: Makefile,v 1.7 2013/10/29 10:55:59 jperkin Exp $
#

DISTNAME=	teseq-1.1
CATEGORIES=	misc
MASTER_SITES=	http://ftp.gnu.org/gnu/teseq/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ftp.gnu.org/gnu/teseq/
COMMENT=	Terminal control sequence analyzer

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c99
USE_TOOLS+=	perl:run sed:run

CONFIGURE_ENV+=	AUTOCONF=true # files pre-built, not needed
CONFIGURE_ENV+= MAKEINFO=true
CONFIGURE_ENV+=	HELP2MAN=true

INFO_FILES=	yes

REPLACE_PERL=	reseq.in
REPLACE_SED=	src/teseq-post.sed
REPLACE_SH=	tests/run.in

REPLACE_INTERPRETER+=	sed
REPLACE.sed.old=	.*sed
REPLACE.sed.new=	${SED}
REPLACE_FILES.sed=	${REPLACE_SED}

SUBST_CLASSES+=	infodir
SUBST_FILES.infodir=	Makefile.in
SUBST_MESSAGE.infodir=	Fixing info directory pathname
SUBST_SED.infodir=	-e 's,@infodir@,${PREFIX}/${PKGINFODIR},g'
SUBST_STAGE.infodir=	pre-configure

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
