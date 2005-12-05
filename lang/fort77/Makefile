# $NetBSD: Makefile,v 1.16 2005/12/05 20:50:25 rillig Exp $
#

DISTNAME=		fort77-1.14a
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SUNSITE:=devel/lang/fortran/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		The driver for f2c, a fortran to C translator

DEPENDS+=		f2c-[0-9]*:../../lang/f2c

# on 1.3.X systems there is not shared libf2c, thus use libf2c.a
# from the f2c package.
.if !exists(/usr/bin/f77)
F2CPKGHASNOSHAREDLIB=	-e 's:-lf2c:'${PREFIX}'/lib/libf2c.a:g'
.else
F2CPKGHASNOSHAREDLIB=
.endif

.if exists(/usr/bin/fort77)
PKG_SKIP_REASON+=	"${PKGNAME} is part of your ${OPSYS} distribution"
.endif

BUILD_TARGET=		test
USE_TOOLS+=		perl:run

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
