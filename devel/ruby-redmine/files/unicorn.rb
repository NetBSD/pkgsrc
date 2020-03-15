working_directory "@PREFIX@/share/@RUBY_PKGPREFIX@-redmine/app"
pid "@PREFIX@/share/@RUBY_PKGPREFIX@-redmine/unicorn.pid"
stderr_path "@PREFIX@/share/@RUBY_PKGPREFIX@-redmine/unicorn.log"
stdout_path "@PREFIX@/share/@RUBY_PKGPREFIX@-redmine/unicorn.log"

worker_processes 3
listen "@PREFIX@/share/@RUBY_PKGPREFIX@-redmine/unicorn.redmine.sock"
timeout 60
