# $NetBSD: Makefile,v 1.43 2012/09/11 23:25:09 asau Exp $

DISTNAME=		scsh-0.6.7
PKGREVISION=		1
CATEGORIES=		shells lang
MASTER_SITES=		http://ftp.scsh.net/pub/scsh/0.6/  \
			${MASTER_SITE_SOURCEFORGE:=scsh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.scsh.net/
COMMENT=		Unix shell embedded into Scheme, with access to all Posix calls
LICENSE=		modified-bsd

NOT_FOR_PLATFORM=	${LP64PLATFORMS}	# Not 64-bit clean.

GNU_CONFIGURE=		yes

BUILD_TARGET=		enough
TEST_TARGET=		check

PKG_SHELL=		bin/scsh

INSTALLATION_DIRS=	share/doc

# Build references from dumped environment variables is not a problem.
CHECK_WRKREF_SKIP+=	lib/scsh/scsh.image
CHECK_WRKREF_SKIP+=	lib/scsh/stripped-scsh.image

REPLACE_INTERPRETER+=	scsh
REPLACE.scsh.old=	.*scsh[^[:space:]]*
REPLACE.scsh.new=	${PREFIX}/bin/scsh
REPLACE_FILES.scsh=	scsh/ekko.scm

post-install:
	@strip ${DESTDIR}${PREFIX}/bin/scsh
	(cd ${WRKSRC} ; \
	 ${INSTALL_DATA} README RELEASE COPYING ${DESTDIR}${PREFIX}/lib/scsh/doc)
	${RM} -f ${DESTDIR}${PREFIX}/share/doc/scsh
	${LN} -fs ${PREFIX}/lib/scsh/doc ${DESTDIR}${PREFIX}/share/doc/scsh

.include "../../mk/bsd.pkg.mk"
