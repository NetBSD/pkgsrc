# $NetBSD: Makefile,v 1.1.1.1 1999/05/15 07:54:27 hubertf Exp $
#

DISTNAME=	cdlabelgen-1.1.3
CATEGORIES=	print
MASTER_SITES=	http://www.red-bean.com/~bwf/software/cdlabelgen/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.red-bean.com/~bwf/software/cdlabelgen/

USE_PERL5=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

post-extract:
	cd ${WRKSRC}; \
	${MV} cdlabelgen cdlabelgen.BAK; \
	${SED} \
		-e 's|/usr/bin/perl|${LOCALBASE}/bin/perl|g' \
		-e 's|/usr/local|${PREFIX}|g' \
		<cdlabelgen.BAK >cdlabelgen

post-install:
	${LOCALBASE}/bin/pod2man ${PREFIX}/bin/cdlabelgen \
		>${PREFIX}/man/man1/cdlabelgen.1

.include "../../mk/bsd.pkg.mk"
