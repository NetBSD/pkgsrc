# $NetBSD: Makefile,v 1.22 2003/06/02 01:16:58 jschauma Exp $
# FreeBSD Id: Makefile,v 1.4 1997/07/15 15:00:30 cracauer Exp
#

DISTNAME=		scsh-0.5.3
CATEGORIES=		shells lang
MASTER_SITES=		ftp://ftp.scsh.net/pub/scsh/0.5/

MAINTAINER= 		tech-pkg@netbsd.org
HOMEPAGE=		http://www.scsh.net/
COMMENT=		Unix shell embedded into Scheme, with access to all Posix calls

NOT_FOR_PLATFORM=	*-*-alpha	# Needs scheme

GNU_CONFIGURE=		yes

ALL_TARGET=		enough

USE_PKGINSTALL=		yes
PKG_SHELL=		${PREFIX}/bin/scsh

post-configure:
	cd ${WRKSRC}; ${SED} -e '/LIBGEN/d' sysdep.h >xx ; ${MV} xx sysdep.h

post-install:
	@strip ${PREFIX}/bin/scsh
	(cd ${WRKSRC} ; \
	 ${INSTALL_DATA} README RELEASE NEWS COPYING ${PREFIX}/lib/scsh/doc)
	${RM} -f ${PREFIX}/share/doc/scsh
	${LN} -fs ${PREFIX}/lib/scsh/doc ${PREFIX}/share/doc/scsh

.include "../../mk/bsd.pkg.mk"
