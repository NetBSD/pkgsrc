# New ports collection makefile for:    a2ps
# Version required:     4.9.9
# Date created:         18 August 1997
# Whom:                 Chuck Robey (chuckr@freebsd.org)
#
# $NetBSD: Makefile,v 1.6 1998/02/23 11:47:07 agc Exp $
# FreeBSD Id: Makefile,v 1.12 1998/02/15 21:24:42 steve Exp
#

DISTNAME=	a2ps-4.9.9
PKGNAME=	a2ps-${PAPERSIZE}-4.9.9
CATEGORIES=	print
MASTER_SITES=	http://www-inf.enst.fr/~demaille/ftp/a2ps/

MAINTAINER=	chuckr@FreeBSD.org

GNU_CONFIGURE=	yes
MAN1=		a2ps.1 ogonkify.1

STRIP=
CONFIGURE_ARGS+=	--with-medium=${PAPERSIZE}
CONFIGURE_ENV+=		LPR=lpr

ALL_TARGET=	all PAPERSIZE=${PAPERSIZE}

pre-build:
	${TOUCH} ${WRKSRC}/doc/*.info
	${TOUCH} ${WRKSRC}/doc/*.dvi

pre-configure:
	@(case "X${PAPERSIZE}" in 					\
	XA4|XLetter|XLetterdj) 						\
		goodsize=yes; 						\
		;; 							\
	X"") 								\
		goodsize=no; 						\
		${ECHO} "PAPERSIZE not specified."; 			\
		;; 							\
	*) 								\
		goodsize=no; 						\
		${ECHO} "PAPERSIZE incorrect value: ${PAPERSIZE}."; 	\
		;; 							\
	esac; 								\
	if [ $$goodsize = "no" ]; then 					\
		${ECHO} ""; 						\
		${ECHO} "Must specify PAPERSIZE as one of A4, Letter,"; \
		${ECHO} "or Letterdj, either in the environment, or ";	\
		${ECHO} "via Makefile definitions of the same name. ";	\
		${ECHO} "Note that each PAPERSIZE has a leading "; 	\
		${ECHO} "capital letter, and Letterdj allows a ";	\
		${ECHO} "slightly larger margins for DeskJets.";	\
		${FALSE}; 						\
	fi)

.include <bsd.port.mk>
