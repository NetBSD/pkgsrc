# $NetBSD: Makefile,v 1.21 2002/11/26 10:13:20 jmmv Exp $
# FreeBSD Id: Makefile,v 1.15 1998/01/08 18:52:13 fenner Exp
#

DISTNAME=	psutils-p17
PKGNAME=	psutils-1.17
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.dcs.ed.ac.uk/pub/ajcd/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.go.dlr.de:8081/pdinfo_dv/psutils.html
COMMENT=	Utilities for manipulating PostScript documents

DEPENDS+=	papersize-[0-9]*:../../print/papersize

WRKSRC=		${WRKDIR}/psutils
USE_PERL5=	yes

.include "../../mk/bsd.prefs.mk"

PAPERSIZE?=	A4

MAKE_ENV+=	CC="${CC}" PERL5="${PERL5}"
MAKE_FLAGS+=	PAPER=`${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'`
MAKEFILE=	Makefile.unix

EGDIR=		${PREFIX}/share/examples/psutils
CONF_FILES=	${EGDIR}/psutils.cfg ${PKG_SYSCONFDIR}/psutils.cfg

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
	for f in epsffit psbook psnup psresize psselect pstops; do	\
		strip ${PREFIX}/bin/$$f;				\
	done
	${INSTALL_DATA_DIR} ${EGDIR}
	low=`${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'`;		\
	${ECHO} "PAPERSIZE=$$low" > ${EGDIR}/psutils.cfg;

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
