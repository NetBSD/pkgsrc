# $NetBSD: Makefile,v 1.27 2020/10/26 10:10:54 schmonz Exp $

DISTNAME=	pdksh-5.2.14
PKGREVISION=	7
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.cs.mun.ca/pub/pdksh/
MASTER_SITES+=	ftp://ftp.lip6.fr/pub/unix/shells/pdksh/
MASTER_SITES+=	ftp://ftp.demon.net/pub/mirrors/pdksh/
MASTER_SITES=	# maintained locally
DISTFILES=	# empty

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/20161021105605/http://web.cs.mun.ca/~michael/pdksh/
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
