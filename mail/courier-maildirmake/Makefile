# $NetBSD: Makefile,v 1.3 2002/01/02 19:26:01 jlam Exp $

DISTNAME=	courier-maildirmake-0.3
CATEGORIES=	mail
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	jlam@netbsd.org
COMMENT=	Wrapper to execute maildirmake

USE_BUILDLINK_ONLY=	# defined
NO_CHECKSUM=		# defined
FILES_SUBST=		LOCALBASE=${LOCALBASE}
FILES_SUBST+=		ECHO=${ECHO}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

do-build:
	${SED} ${FILES_SUBST_SED} \
		${FILESDIR}/maildirmake.sh > ${WRKDIR}/maildirmake.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/maildirmake.sh ${PREFIX}/bin/maildirmake

.include "../../mk/bsd.pkg.mk"
