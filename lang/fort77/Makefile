# $NetBSD: Makefile,v 1.8 2001/05/19 03:56:36 jlam Exp $
#

DISTNAME=		fort77-1.14a
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SUNSITE:=devel/lang/fortran/}

MAINTAINER=		packages@netbsd.org
COMMENT=		the driver for f2c, a fortran to C translator

DEPENDS+=		f2c-*:../../lang/f2c

# on 1.3.X systems there is not shared libf2c, thus use libf2c.a
# from the f2c package.
.if !exists(/usr/bin/f77)
F2CPKGHASNOSHAREDLIB=	-e 's:-lf2c:'${PREFIX}'/lib/libf2c.a:g'
.else
F2CPKGHASNOSHAREDLIB=
.endif

.if exists(/usr/bin/fort77)
IGNORE=			"${PKGNAME} is part of your NetBSD distribution"
.endif

ALL_TARGET=		test

USE_PERL5=		YES

post-patch:
	for f in `${FIND} ${WRKDIR} -type f -print | ${XARGS} ${GREP} -l '/usr'`; \
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
