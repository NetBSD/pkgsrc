# $NetBSD: Makefile,v 1.5 2006/07/06 21:14:19 jlam Exp $

DISTNAME=	p5-pkgsrc-Dewey-1.0
PKGREVISION=	1
CATEGORIES=	pkgtools perl5
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/Documentation/pkgsrc/
COMMENT=	Perl module to compare pkgsrc Dewey numbers

CPPFLAGS+=	-DHAVE_CTYPE_H -DHAVE_STDLIB_H -DHAVE_STRING_H

NO_CHECKSUM=	yes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=         auto/pkgsrc/Dewey/.packlist

PKG_INSTALL_FILESDIR=	../../pkgtools/pkg_install/files
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
