# $NetBSD: Makefile,v 1.6 1998/04/20 11:56:32 frueauf Exp $
# FreeBSD Id: Makefile,v 1.15 1998/01/08 18:52:13 fenner Exp
#

DISTNAME=	psutils-p17
PKGNAME=	psutils-${PAPERSIZE}-1.17
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.dcs.ed.ac.uk/pub/ajcd/

MAINTAINER=	packages@netbsd.org

MANUAL_PACKAGE_BUILD=	PAPERSIZE has to be set to letter or A4
WRKSRC=		${WRKDIR}/psutils
MAKE_FLAGS?=	PAPER=${PAPERSIZE} -f
MAN1=		psbook.1 psselect.1 pstops.1 epsffit.1 psnup.1 psresize.1 \
		getafm.1 fixdlsrps.1 fixfmps.1 fixmacps.1 fixpsditps.1 \
		fixpspps.1 fixtpps.1 fixwfwps.1 fixwpps.1 fixwwps.1 \
		extractres.1 includeres.1 fixscribeps.1 psmerge.1

PAPERSIZE?=	A4
USE_PERL5=	YES

pre-configure:
	@case "X${PAPERSIZE}" in					\
	XA4|XLetter)							\
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
