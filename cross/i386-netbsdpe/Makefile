# $NetBSD: Makefile,v 1.1.1.1 2000/11/06 03:15:14 minoura Exp $
#

DISTVERSION=		1.0.0.0
DISTFILES=		# none

MAINTAINER=		peace-sacrifice@hauN.ORG
HOMEPAGE=		http://chiharu.hauN.ORG/peace/

WRKSRC=			${WRKDIR}/${EGCS_DISTNAME}

USE_CROSS_BINUTILS=	yes
BINUTILS_GNUTARGET=	pe-i386
BINUTILS_LDEMULATION=	i386pe
USE_CROSS_EGCS=		yes
EGCS_FAKE_RUNTIME=	yes

TARGET_ARCH=		i386-netbsdpe

BINUTILS_EXTRAS=	dlltool windres

post-patch:
	for i in patches/binutils-*; do \
		${PATCH} -d ${BINUTILS_WRKSRC} --forward --quiet -E < $$i; \
	done
	cd ${BINUTILS_WRKSRC}/bfd && autoconf
	cd ${BINUTILS_WRKSRC}/gas && autoconf
	cd ${WRKDIR}/${EGCS_DISTNAME}/gcc && autoconf
post-configure:
	${CP} ${FILESDIR}/i386_limits.h ${SYS_INCLUDE}/machine/limits.h
	${CP} ${FILESDIR}/syslimits.h ${SYS_INCLUDE}/sys/
	${CP} ${FILESDIR}/featuretest.h ${SYS_INCLUDE}/sys/
	${CP} ${FILESDIR}/limits.h ${SYS_INCLUDE}/

.include "../COMMON/cross.mk"
