# $NetBSD: Makefile,v 1.1.1.1 1999/01/14 15:48:29 frueauf Exp $
#

DISTNAME=		fort77-1.14a
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	devel/lang/fortran

MAINTAINER=		packages@netbsd.org

DEPENDS+=		f2c-19980913:../../lang/f2c

# on 1.3.X systems there is not shared libf2c, thus use libf2c.a
# from the f2c package.
.if !exists(/usr/bin/f77)
F2CPKGHASNOSHAREDLIB=	-e 's:-lf2c:'${PREFIX}'/lib/libf2c.a:g'
.else
F2CPKGHASNOSHAREDLIB=
.endif

.if exists(/usr/bin/fort77)
IGNORE=			"is part of your NetBSD distribution"
.endif

ALL_TARGET=		test

USE_PERL5=		YES

post-patch:
	for f in `find ${WRKDIR} -type f -print|xargs ${GREP} -l '/usr'`; \
	do \
	  ${SED} -e 's:/usr:'${PREFIX}':g' <$$f >$$f.pdone && \
	  ${MV} $$f.pdone $$f; \
	done
	${SED} -e 's:/lib/cpp:/usr/bin/cpp:g' ${F2CPKGHASNOSHAREDLIB} \
		< ${WRKSRC}/fort77  > ${WRKSRC}/fort77.new
	${MV} ${WRKSRC}/fort77.new ${WRKSRC}/fort77
	${CHMOD} +x ${WRKSRC}/fort77
	${CHMOD} +x ${WRKSRC}/tests/test.pl

.include "../../mk/bsd.pkg.mk"
