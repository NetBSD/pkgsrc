# $NetBSD: Makefile,v 1.4 2012/10/31 11:16:50 asau Exp $
#

DISTNAME=	cvsdiff2patch-1.0.1
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://people.freebsd.org/~alfred/sources/cvsdiff2patch/
COMMENT=	Convert CVS diffs into something that patch(1) understands

NO_CONFIGURE=	yes
USE_LIBTOOL=	yes

INSTALLATION_DIRS+=	bin

do-extract:
	${RUN} ${CP} -R ${FILESDIR} ${WRKSRC}

do-build:
	${RUN} cd ${WRKSRC} && \
	${LIBTOOL} --mode=link ${CC} -o ${PKGBASE} ${PKGBASE}.c

do-install:
	${RUN} cd ${WRKSRC} && \
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${PKGBASE} \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
