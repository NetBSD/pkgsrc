# $NetBSD: Makefile,v 1.12 1998/06/22 13:04:37 agc Exp $
# FreeBSD Id: Makefile,v 1.12 1998/02/15 21:24:42 steve Exp
#

DISTNAME=	a2ps-4.9.9
PKGNAME=	a2ps-${PAPERSIZE}-4.9.9
CATEGORIES=	print
MASTER_SITES=	http://www-inf.enst.fr/~demaille/ftp/a2ps/

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=	yes

STRIP=
CONFIGURE_ARGS+=	--with-medium=${PAPERSIZE}
CONFIGURE_ENV+=		LPR=lpr
USE_GTEXINFO=		YES
INFO_FILES=		a2ps.info ogonkify.info regex.info

ALL_TARGET=	all PAPERSIZE=${PAPERSIZE}

PAPERSIZE?=	A4

pre-build:
	${TOUCH} ${WRKSRC}/doc/*.info
	${TOUCH} ${WRKSRC}/doc/*.dvi

pre-configure:
	@(case "X${PAPERSIZE}" in 					\
	XA4|XLetter|XLetterdj) 						\
		goodsize=yes; 						\
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

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
