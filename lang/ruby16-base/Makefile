# $NetBSD: Makefile,v 1.1.1.1 2005/03/06 16:36:08 taca Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-base-${RUBY_VERSION}
CATEGORIES=	lang ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Ruby 1.6 baed release minimum package

RUBY_VERSION=		${RUBY16_VERSION}
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		test
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ENV+=		PREFIX="${PREFIX}"
BUILD_DEFS+=		USE_INET6

# Ruby build process depends on config.status's content
CONFIG_STATUS_OVERRIDE=	# empty

.include "../../lang/ruby/rubyversion.mk"

.if !empty(RUBY_SUFFIX)
CONFIGURE_ARGS+= --program-suffix="${RUBY_SUFFIX}"
.endif
.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+= --enable-ipv6
.endif

DOCS=		ChangeLog README README.EXT README.EXT.ja README.ja ToDo \
		doc/NEWS doc/forwardable.rd doc/forwardable.rd.ja \
		doc/shell.rd doc/shell.rd.ja doc/irb/irb-tools.rd.ja \
		doc/irb/irb.rd doc/irb/irb.rd.ja doc/net/http.rd.ja \
		doc/net/pop.rd.ja doc/net/smtp.rd.ja doc/shell.rd \
		doc/shell.rd.ja
EXT_DOCS=	etc/etc.txt etc/etc.txt.ja syslog/syslog.txt
PTY_ROCS=	README README.expect README.expect.ja README.ja

REPLACE_RUBY=	bin/irb \
		lib/matrix.rb sample/biorhythm.rb sample/cal.rb \
		sample/exyacc.rb sample/from.rb sample/fullpath.rb \
		sample/goodfriday.rb sample/less.rb \
		sample/mine.rb sample/mpart.rb sample/observ.rb \
		sample/pi.rb sample/rcs.rb sample/test.rb \
		sample/time.rb sample/trojan.rb sample/uumerge.rb

pre-configure:
	${RM} -f ${WRKSRC}/ext/curses/MANIFEST
	${RM} -f ${WRKSRC}/ext/dbm/MANIFEST
	${RM} -f ${WRKSRC}/ext/gdbm/MANIFEST
	${RM} -f ${WRKSRC}/ext/digest/MANIFEST
	${RM} -f ${WRKSRC}/ext/digest/md5/MANIFEST
	${RM} -f ${WRKSRC}/ext/digest/rmd160/MANIFEST
	${RM} -f ${WRKSRC}/ext/digest/sha1/MANIFEST
	${RM} -f ${WRKSRC}/ext/digest/sha2/MANIFEST
	${RM} -f ${WRKSRC}/ext/readline/MANIFEST
	${RM} -f ${WRKSRC}/ext/tcltklib/MANIFEST
	${RM} -f ${WRKSRC}/ext/tk/MANIFEST
	${RM} -f ${WRKSRC}/sample/dbmtest.rb

pre-build:
	@${FIND} ${WRKSRC} -name '*.orig' -exec ${RM} -f {} \;

post-install:
	${STRIP} ${RUBY}
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/irb
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/net
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/pty
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${f:C/^doc\///}
.endfor
.for f in ${EXT_DOCS}
	${INSTALL_DATA} ${WRKSRC}/ext/${f} ${RUBY_DOCDIR}
.endfor
.for f in ${PTY_ROCS}
	${INSTALL_DATA} ${WRKSRC}/ext/pty/${f} ${RUBY_DOCDIR}/pty/${f}
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/irb ${PREFIX}/bin/irb16
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/pty
	${INSTALL_DATA} ${WRKSRC}/ext/pty/expect_sample.rb \
		${WRKSRC}/ext/pty/script.rb ${WRKSRC}/ext/pty/shl.rb \
		${RUBY_EXAMPLESDIR}/pty

.include "../../lang/ruby/Makefile.common"
.include "../../mk/bsd.pkg.mk"
