# $NetBSD: Makefile,v 1.13 1999/02/20 22:48:42 hubertf Exp $
# FreeBSD Id: Makefile,v 1.15 1998/01/08 18:52:13 fenner Exp
#

DISTNAME=	psutils-p17
PKGNAME=	psutils-1.17
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.dcs.ed.ac.uk/pub/ajcd/

MAINTAINER=	packages@netbsd.org

DEPENDS+=	papersize-1.0:../../print/papersize

WRKSRC=		${WRKDIR}/psutils
USE_PERL5=	yes

.include "../../mk/bsd.prefs.mk"

PAPERSIZE?=	A4
MAKE_FLAGS+=	PAPER=`${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'`

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
		${ECHO} "   A3, A4 (default), A5, B5, Letter, Legal,";	\
		${ECHO} "   Ledger, Tabloid, Statement, Executive,";	\
		${ECHO} "   Folio, Quarto, and 10x14.";			\
		${FALSE};						\
		;;							\
	esac

post-patch:
	${MV} ${WRKSRC}/psutil.c ${WRKSRC}/psutil.c.in
	${SED} -e 's|@prefix@|${PREFIX}|g' ${WRKSRC}/psutil.c.in > ${WRKSRC}/psutil.c

post-install:
	for file in epsffit psbook psnup psresize psselect pstops; do	\
		strip ${PREFIX}/bin/$$file;				\
	done
	low=`${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'`;		\
	if [ ! -e ${PREFIX}/etc/psutils.cfg ]; then			\
		${ECHO} "PAPERSIZE=$$low" > ${PREFIX}/etc/psutils.cfg;	\
	fi

.include "../../mk/bsd.pkg.mk"
