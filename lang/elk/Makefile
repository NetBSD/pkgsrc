# $NetBSD: Makefile,v 1.15 2000/08/23 21:53:55 wiz Exp $
# FreeBSD Id: Makefile,v 1.15 1997/09/01 12:28:30 tg Exp
#

DISTNAME=		elk-3.0
PKGNAME=		elk-3.0.2
CATEGORIES=		lang
MASTER_SITES=		http://www-rn.informatik.uni-bremen.de/software/elk/dist/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www-rn.informatik.uni-bremen.de/software/elk/

NOT_FOR_PLATFORM=	*-*-alpha *-*-mips*	#elf loading problems, LP64

ALL_TARGET=		default
USE_X11=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "ELF" && ${OPSYS} == "NetBSD"
IGNORE+=	"${PKGNAME} has not yet been ported to NetBSD ELF platforms"
.endif

do-configure:
	@case `${MAKE} show-shlib-type` in				\
	a.out)	exetype=aout ;;						\
	ELF)	exetype=elf ;;						\
	esac;								\
	${ECHO} "Setting up links for $$exetype on ${LOWER_OPSYS}";	\
	${RM} -f ${WRKSRC}/config/untested/elf-solaris-cc;		\
	${LN} -s ${WRKSRC}/config/sun-sunos5-gcc ${WRKSRC}/config/untested/elf-solaris-cc; \
	${RM} -f ${WRKSRC}/config/system ${WRKSRC}/config/site;		\
	${LN} -s ${WRKSRC}/config/untested/$$exetype-${LOWER_OPSYS}-cc ${WRKSRC}/config/system; \
	for f in aout-netbsd elf-netbsd elf-solaris; do			\
		${RM} -f ${WRKSRC}/config/sites/$$f;			\
		${LN} -s ${WRKSRC}/config/sites/pkgsrc ${WRKSRC}/config/sites/$$f; \
	done;								\
	${LN} -s ${WRKSRC}/config/sites/$$exetype-${LOWER_OPSYS} ${WRKSRC}/config/site

.include "../../mk/bsd.pkg.mk"
