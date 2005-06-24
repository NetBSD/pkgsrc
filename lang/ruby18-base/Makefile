# $NetBSD: Makefile,v 1.5.2.1 2005/06/24 08:40:44 salo Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-base-${RUBY_VERSION}
PKGREVISION=	2
CATEGORIES=	lang ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Ruby 1.8 based release minimum package

RUBY_VERSION=		${RUBY18_VERSION}
GNU_CONFIGURE=		yes
TEST_TARGET=		test
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ENV+=		PREFIX="${PREFIX}"
INSTALL_TARGET=		install install-doc
WRKSRC=			${RUBY_WRKSRC}

# Ruby build process depends on config.status's content
CONFIG_STATUS_OVERRIDE=	# empty

.include "../../lang/ruby/rubyversion.mk"

.if !empty(RUBY_SUFFIX)
CONFIGURE_ARGS+= --program-suffix="${RUBY_SUFFIX}"
.endif

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "IRIX"
PLIST_SUBST+=  HAS_IO="@comment "
.else
PLIST_SUBST+=  HAS_IO=
.endif

DOCS=		COPYING COPYING.ja ChangeLog README \
		README.EXT README.EXT.ja README.ja ToDo \
		doc/ChangeLog-1.8.0 doc/NEWS \
		doc/forwardable.rd doc/forwardable.rd.ja \
		doc/shell.rd doc/shell.rd.ja doc/irb/irb-tools.rd.ja \
		doc/irb/irb.rd doc/irb/irb.rd.ja
EXT_DOCS=	bigdecimal/bigdecimal_en.html bigdecimal/bigdecimal_ja.html \
		dl/doc/dl.txt enumerator/enumerator.txt \
		etc/etc.txt etc/etc.txt.ja syslog/syslog.txt

BIGDECIMAL_EXAMPLES=	linear.rb nlsolve.rb pi.rb
DL_EXAMPLES=		c++sample.C c++sample.rb drives.rb getch.rb libc.rb \
			msgbox.rb msgbox2.rb stream.rb
PTY_EXAMPLES=		expect_sample.rb script.rb shl.rb

REPLACE_RUBY=	bin/erb bin/irb bin/rdoc bin/ri bin/testrb \
		ext/bigdecimal/sample/linear.rb \
		ext/bigdecimal/sample/nlsolve.rb \
		ext/bigdecimal/sample/pi.rb \
		lib/rdoc/markup/sample/rdoc2latex.rb \
		sample/biorhythm.rb sample/cal.rb sample/exyacc.rb \
		sample/fullpath.rb sample/less.rb sample/from.rb \
		sample/goodfriday.rb sample/logger/shifting.rb \
		sample/logger/app.rb sample/logger/log.rb sample/mine.rb \
		sample/mpart.rb sample/observ.rb sample/optparse/opttest.rb \
		sample/openssl/c_rehash.rb sample/openssl/cert2text.rb \
		sample/openssl/cert_store_view.rb \
		sample/openssl/certstore.rb sample/openssl/cipher.rb \
		sample/openssl/crlstore.rb sample/openssl/echo_cli.rb \
		sample/openssl/echo_svr.rb sample/openssl/gen_csr.rb \
		sample/openssl/smime_read.rb sample/openssl/smime_write.rb \
		sample/openssl/wget.rb \
		sample/soap/calc/httpd.rb sample/soap/calc/server.rb \
		sample/soap/calc/server2.rb sample/soap/icd/icd.rb \
		sample/soap/babelfish.rb sample/soap/exchange/client.rb \
		sample/soap/exchange/httpd.rb sample/soap/exchange/server.rb \
		sample/soap/raa/soap4r.rb sample/soap/sampleStruct/httpd.rb \
		sample/soap/sampleStruct/server.rb sample/pi.rb \
		sample/wsdl/amazon/sampleClient.rb \
		sample/wsdl/googleSearch/sampleClient.rb \
		sample/wsdl/googleSearch/httpd.rb sample/wsdl/raa/soap4r.rb \
		sample/test.rb 	sample/trojan.rb sample/time.rb \
		sample/uumerge.rb

pre-configure:
	${RM} -f ${WRKSRC}/ext/curses/extconf.rb
	${RM} -f ${WRKSRC}/ext/dbm/extconf.rb
	${RM} -f ${WRKSRC}/ext/digest/extconf.rb
	${RM} -f ${WRKSRC}/ext/digest/md5/extconf.rb
	${RM} -f ${WRKSRC}/ext/digest/rmd160/extconf.rb
	${RM} -f ${WRKSRC}/ext/digest/sha1/extconf.rb
	${RM} -f ${WRKSRC}/ext/digest/sha2/extconf.rb
	${RM} -f ${WRKSRC}/ext/gdbm/extconf.rb
	${RM} -f ${WRKSRC}/ext/iconv/extconf.rb
	${RM} -f ${WRKSRC}/ext/openssl/extconf.rb
	${RM} -f ${WRKSRC}/ext/readline/extconf.rb
	${RM} -f ${WRKSRC}/ext/tcltklib/extconf.rb
	${RM} -f ${WRKSRC}/ext/tk/extconf.rb
	${RM} -f ${WRKSRC}/ext/zlib/extconf.rb
	${RM} -f ${WRKSRC}/sample/dbmtest.rb
	${RM} -fr ${WRKSRC}/sample/openssl

pre-build:
	@${FIND} ${WRKSRC} -name '*.orig' -exec ${RM} -f {} \;

post-install:
	${STRIP} ${RUBY}
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/irb
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/pty
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${f:C/^doc\///}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/ext/dl/h2rb ${PREFIX}/bin/h2rb${RUBY_VER}
.for f in ${EXT_DOCS}
	${INSTALL_DATA} ${WRKSRC}/ext/${f} ${RUBY_DOCDIR}
.endfor
	${CP} -r ${WRKSRC}/ext/pty/README.* ${RUBY_DOCDIR}/pty
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/pty
	${CP} -r ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/bigdecimal
.for f in ${BIGDECIMAL_EXAMPLES}
	${INSTALL_DATA} ${RUBY_WRKSRC}/ext/bigdecimal/sample/${f} \
		${RUBY_EXAMPLESDIR}/bigdecimal
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/dl
.for f in ${DL_EXAMPLES}
	${INSTALL_DATA} ${RUBY_WRKSRC}/ext/dl/sample/${f} \
		${RUBY_EXAMPLESDIR}/dl
.endfor
.for f in ${PTY_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/ext/pty/${f} ${RUBY_EXAMPLESDIR}/pty
.endfor

.include "../../lang/ruby/Makefile.common"
.include "../../mk/bsd.pkg.mk"
