# $NetBSD: Makefile,v 1.24 2016/06/05 04:44:56 richard Exp $
#

DISTNAME=	pdksh-5.2.14
PKGREVISION=	7
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
