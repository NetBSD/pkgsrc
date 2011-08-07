# $NetBSD: Makefile,v 1.18 2011/08/07 08:15:05 tron Exp $

DISTNAME=	p5-pkgsrc-Dewey-1.1
PKGREVISION=	2
CATEGORIES=	pkgtools perl5
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/docs/pkgsrc/
COMMENT=	Perl module to compare pkgsrc Dewey numbers
LICENSE=	${PERL5_LICENSE} OR 2-clause-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

CPPFLAGS+=	-DHAVE_CTYPE_H -DHAVE_STDLIB_H -DHAVE_STRING_H
CPPFLAGS.NetBSD+=	-DHAVE_ERR_H

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/pkgsrc/Dewey/.packlist

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
