# XXX snarf and atfify the tests from regress/buildlink-transform

test: Atffile test-lib-expand test-remove-dir
	atf-run

clean:
	rm -f test-lib-expand test-remove-dir

test-lib-expand: test-lib-expand.sh
	atf-compile -o test-lib-expand test-lib-expand.sh

test-remove-dir: test-remove-dir.sh
	atf-compile -o test-remove-dir test-remove-dir.sh
