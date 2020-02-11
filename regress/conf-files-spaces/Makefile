# $NetBSD: Makefile,v 1.1 2020/02/11 01:59:30 rillig Exp $
#
# Requires bmake from 2015 or later, since in previous versions, the .for
# loop did split the variable values strictly on spaces, without taking
# backslashes or quotes into account.

PKGNAME=	conf-files-spaces-2020.02.11
CATEGORIES=	misc
DISTFILES=	# none

COMMENT=	Demonstrates spaces in configuration file names
LICENSE=	2-clause-bsd

BUILD_DIRS=	# none
EGDIR=		share/${PKGBASE}
EGFILES=	back\ slash.conf "d quot.conf" 's quot.conf'

.for file in ${EGFILES}
CONF_FILES+=	${EGDIR}/${file} ${PKG_SYSCONFDIR}/${file}
.endfor

do-install:
	mkdir ${DESTDIR}${PREFIX}/${EGDIR}
.for file in ${EGFILES}
	${INSTALL_DATA} /dev/null ${DESTDIR}${PREFIX}/${EGDIR}/${file}
.endfor

.include "../../mk/bsd.pkg.mk"
