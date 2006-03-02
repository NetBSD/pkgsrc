# $NetBSD: Makefile,v 1.2 2006/03/02 10:53:39 tron Exp $

DISTNAME=	p5-pkgsrc-Dewey-1.0
CATEGORIES=	pkgtools perl5
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.netbsd.org/Documentation/pkgsrc/
COMMENT=	Perl module to compare pkgsrc Dewey numbers

CPPFLAGS+=	-DHAVE_CTYPE_H -DHAVE_STDLIB_H

NO_CHECKSUM=	yes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=         auto/pkgsrc/Dewey/.packlist

PKG_INSTALL_FILESDIR=	../../pkgtools/pkg_install/files
PKG_INSTALL_FILES=	lib/dewey.c lib/dewey.h lib/defs.h

do-extract:
	${MKDIR} ${WRKSRC}/lib
	${CP} -r ${FILESDIR}/* ${WRKSRC}
	for f in ${PKG_INSTALL_FILES}; do \
		${CP} ${PKG_INSTALL_FILESDIR}/$$f ${WRKSRC}/lib; \
	done
	${TOUCH} ${WRKSRC}/nbcompat.h

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
