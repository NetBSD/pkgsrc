# $NetBSD: Makefile,v 1.9 1998/08/14 20:59:43 frueauf Exp $
# FreeBSD Id: Makefile,v 1.15 1998/01/08 18:52:13 fenner Exp
#

DISTNAME=	psutils-p17
PKGNAME=	psutils-${PAPERSIZE}-1.17
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.dcs.ed.ac.uk/pub/ajcd/

MAINTAINER=	packages@netbsd.org

MANUAL_PACKAGE_BUILD=	PAPERSIZE has to be set to letter or A4
WRKSRC=		${WRKDIR}/psutils
MAKE_FLAGS?=	PAPER=${PAPERSIZE}

PAPERSIZE?=	A4
USE_PERL5=	YES

pre-configure:
	@case "X${PAPERSIZE}" in					\
	XA4|Xletter)							\
		;;							\
	XA3|XA5|XB5|Xledger|Xstatement|Xexecutive|Xfolio|Xquarto|X10x14)\
		${ECHO} "Other packages do not recognise ${PAPERSIZE}";	\
		;;							\
	*)								\
		${ECHO} "Error: PAPERSIZE invalid: \"${PAPERSIZE}\"";	\
		${ECHO} "Possible values are:";				\
		${ECHO} "   A3, A4 (default), A5, B5, letter, legal,";	\
		${ECHO} "   ledger, tabloid, statement, executive,";	\
		${ECHO} "   folio, quarto, and 10x14.";			\
		${FALSE};						\
		;;							\
	esac

post-install:
.for file in epsffit psbook psnup psresize psselect pstops
	strip ${PREFIX}/bin/${file}
.endfor

.include "../../mk/bsd.pkg.mk"
