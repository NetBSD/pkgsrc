# $NetBSD#


SRC = s_server.c s_socket.c s_cb.c

# For Solaris2.6
#EXTLIBS = -lxnet

# Debug/Optimizations
#OPT = -g
OPT = -O2

# Define 
OPENSSL="\"openssl/\""
#OPENSSL=""

all :
	gcc -o sslwrap ${SRC} ${OPT} -DFLAT_INC -DOPENSSL=${OPENSSL} \
		${SSL_LIBDIR} -lssl -lcrypto \
		${SSL_INCDIR} \
		${EXTLIBS}

clean:
	rm -f sslwrap *.o *~






