# $NetBSD: Makefile,v 1.21 2012/09/11 23:25:09 asau Exp $
#

DISTNAME=	pdksh-5.2.14
PKGREVISION=	5
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.cs.mun.ca/pub/pdksh/ \
		http://gd.tuwien.ac.at/utils/shells/pdksh/ \
		ftp://ftp.lip6.fr/pub/unix/shells/pdksh/ \
		ftp://ftp.demon.net/pub/mirrors/pdksh/
MASTER_SITES=	# maintained locally
DISTFILES=	# empty

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://web.cs.mun.ca/~michael/pdksh/
COMMENT=	Free clone of the AT&T Korn shell

PKG_INSTALLATION_TYPES=	overwrite pkgviews
BOOTSTRAP_PKG=	yes

GNU_CONFIGURE=		yes

PKG_SHELL=	bin/pdksh

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ksh ${DESTDIR}${PREFIX}/bin/pdksh
	${INSTALL_MAN} ${WRKSRC}/ksh.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pdksh.1

.include "../../mk/bsd.pkg.mk"
