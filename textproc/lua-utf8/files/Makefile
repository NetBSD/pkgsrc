all: lua-utf8.so

lutf8lib.o:
	$(CC) $(CFLAGS) -fPIC -c lutf8lib.c

lua-utf8.so: lutf8lib.o
	$(CC) $(LDFLAGS) -shared -o lua-utf8.so lutf8lib.o
