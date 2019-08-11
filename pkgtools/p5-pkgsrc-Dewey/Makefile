# $NetBSD: Makefile,v 1.33 2019/08/11 13:22:35 wiz Exp $

PKGNAME=	p5-pkgsrc-Dewey-1.1
PKGREVISION=	10
CATEGORIES=	pkgtools perl5

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/docs/pkgsrc/
COMMENT=	Perl module to compare pkgsrc Dewey numbers
LICENSE=	${PERL5_LICENSE} OR 2-clause-bsd

CPPFLAGS+=		-DHAVE_CTYPE_H -DHAVE_STDLIB_H -DHAVE_STRING_H
CPPFLAGS.NetBSD+=	-DHAVE_ERR_H
CPPFLAGS.Linux+=	-fPIC

USE_LANGUAGES=		c
USE_FEATURES+=		err
MAKE_ENV+=		LIBS=${LIBS:Q}

PERL5_PACKLIST=		auto/pkgsrc/Dewey/.packlist

PKG_INSTALL_FILESDIR=	${PKGSRCDIR}/pkgtools/pkg_install/files
PKG_INSTALL_FILES=	lib/dewey.c lib/dewey.h lib/defs.h

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} -r ${FILESDIR}/* ${WRKSRC}
	for f in ${PKG_INSTALL_FILES}; do \
		${CP} ${PKG_INSTALL_FILESDIR}/$$f ${WRKSRC}; \
	done
	${MV} ${WRKSRC}/dewey.c ${WRKSRC}/lib_dewey.c
	${TOUCH} ${WRKSRC}/nbcompat.h

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
