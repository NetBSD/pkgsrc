# $NetBSD: Makefile,v 1.1.1.1 2008/01/06 12:00:29 obache Exp $

DISTNAME=	im-149
CATEGORIES=	mail
MASTER_SITES=	http://tats.haun.org/im/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://tats.haun.org/im/
COMMENT=	E-Mail and NetNews user interface commands

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl:run

CONFIGURE_ARGS+=	--libdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--with-perldir=${PREFIX}/${PERL5_SUB_INSTALLVENDORLIB}
CONFIGURE_ENV+=		im_path_perl=${PERL5:Q}

PKG_SYSCONFSUBDIR=	im

CONF_FILES=	${PREFIX}/share/examples/im/SiteConfig ${PKG_SYSCONFDIR}/SiteConfig

DOCDIR=		${PREFIX}/share/doc/im
EXAMPLESDIR=	${PREFIX}/share/examples/im
DOCS=		00changes 00copyright 00copyright.jis 00perl 00readme 00usage
MAN=		imput
MAN_JA=		imali.jis imcat.jis imcd.jis imclean.jis imget.jis	\
		imhist.jis imjoin.jis immv.jis impack.jis imput.jis	\
		imrm.jis imsetup.jis imsort.jis imstore.jis imtar.jis

INSTALLATION_DIRS+=	${DOCDIR} ${EXAMPLESDIR} ${DOCDIR}/man ${DOCDIR}/man/ja

post-install:
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCDIR}
.endfor
.for file in ${MAN}
	${INSTALL_DATA} ${WRKSRC}/man/${file} ${DOCDIR}/man
.endfor
.for file in ${MAN_JA}
	${INSTALL_DATA} ${WRKSRC}/man/${file} ${DOCDIR}/man/ja
.endfor
	cp -r ${WRKSRC}/dot.im/* ${EXAMPLESDIR}

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
